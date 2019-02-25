#include<iostream>
using namespace std;
class BT
{
public:
    char data;                    //����δ֪��
    BT *lchild,*rchild;
    void creat(BT* &t)            //���Ĵ���
    {
        char s;
        cin>>s;
        if(s=='^')                //������^ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�

            t=NULL;
        else
        {
            t=new BT;
            t->data=s;
            creat(t->lchild);
            creat(t->rchild);
        }
    }
    void preorder(BT *t)         //�������
    {
        if(t)
        {
            cout<<t->data<<" ";
            preorder(t->lchild);
            preorder(t->rchild);
        }
    }
    void inorder(BT *t)         //�������
    {
        if(t)
        {
            inorder(t->lchild);
            cout<<t->data<<" ";
            inorder(t->rchild);
        }
    }
    void postorder(BT *t)         //�������
    {
        if(t)
        {
            postorder(t->lchild);
            postorder(t->rchild);
            cout<<t->data<<" ";
        }
    }
    void Insert(BT* &t,int a)    //���뺯��
    {
        if(t)
        {
            if(t->data<a)
                Insert(t->rchild,a);
            else
                Insert(t->lchild,a);
        }
        else
        {
            t=new BT;
            t->data=a;
            t->lchild=NULL;
            t->rchild=NULL;
        }
    }
};
int main()
{
    BT b;
    BT *t;
    char a;
    b.creat(t);
    cout<<"�������������"<<endl;
    cout<<"ǰ�����Ϊ��"<<endl;
    b.preorder(t);
    cout<<endl;
    cout<<"�������Ϊ��"<<endl;
    b.inorder(t);
    cout<<endl;
    cout<<"�������Ϊ��"<<endl;
    b.postorder(t);
    cout<<endl;
    cout<<"������������:";
    cin>>a;
    b.Insert(t,a);
    cout<<"�����ǰ�����Ϊ��"<<endl;
    b.preorder(t);
}
