#include "DS.h"

/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{
p->tree.a[p->tree.len] = x;
        p->tree.len++;        /* Энд оруулах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
int l = 2 * idx + 1;
        if (l > p->tree.len)
                return -1;
        return l;        /* Энд зүүн хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
int r = 2 * idx + 2;
        if (r >= p->tree.len)
                return -1;
        return r;        /* Энд баруун хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
for (int i = 0; i < p->tree.len; i++)
                if (p->tree.a[i] == x)
                        return i;
        return -1;        /* Энд хайх үйлдлийг хийнэ */	
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
 while (idx > 0) {
                printf("%d\n", p->tree.a[idx]);
                idx = (idx - 1) / 2;
        }        /* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{
int h = 0;
        int n = p->tree.len;
        while (n > 1) {
                n /= 2;
        }
        return h;        /* Энд өндрийг олох үйлдлийг хийнэ */
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
if (idx <= 0)
                return -1;
        if (idx % 2 == 1)
                return idx - 1;
        return idx + 1;        /* Энд ах, дүүг олох үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
if (idx < 0 || idx >= p->tree.len)
                return;
        printf("%d\n", p->tree.a[idx]);
        cb_preorder(p, cb_left(p, idx));
        cb_preorder(p, cb_right(p, idx));        /* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
if (idx < 0 || idx >= p->tree.len)
                return;
        cb_inorder(p, cb_left(p, idx));
        printf("%d\n", p->tree.a[idx]);
        cb_inorder(p, cb_right(p, idx));        /* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
if (idx < 0 || idx >= p->tree.len)
                return;
        printf("%d\n", p->tree.a[idx]);
        cb_postorder(p, cb_left(p, idx));
        cb_postorder(p, cb_right(p, idx));        /* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
if (idx < 0 || idx >= p->tree.len)
                return;
        int l = cb_left(p, idx);
        int r = cb_right(p, idx);
        if (l == -1 && r == -1) {
                printf("%d\n", p->tree.a[idx]);
                return;
        }
        cb_leaves(p, l);
        cb_leaves(p, r);        /* Энд навчуудыг үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
cb_preorder(p, idx);        /* Энд үр садыг олох үйлдлийг хийнэ үү */
}


/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
return p->tree.len;        /* Энд хэмжээг олох үйлдлийг хийнэ үү */	
}


/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
int idx = cb_search(p, x);
        if (idx == -1)
                return -1;
        int level = 1;                  /* алдаа 7 */
        while (idx > 0) {
                idx = (idx - 1) / 2;
                level++;
        }
        return level;        /* Энд түвшинг олох үйлдлийг хийнэ үү */
}

