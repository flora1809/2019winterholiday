#include<iostream>
using namespace std;
class alter
{
public:
    string text;
    alter *next;
    void add(string t,alter *p)
    {
        while(p->next)
        {
            p=p->next;
        }
        alter *s=new alter;
        s->next=p->next;
        p->next=s;
        s->text=t;
        cout<<"��ӳɹ�"<<endl;
    }
    void del(alter *p,string t)
    {
        alter *n,*m=p;
        while(m->next)
        {
            if(m->text==t)
            {
                n=m;
                break;
            }
            else
                m=m->next;
        }
        m=p;
        while(m->next!=n)
        {
            m=m->next;
        }
        m->next=m->next->next;
        cout<<"ɾ���ɹ�"<<endl;
    }
    void alt(alter *p,string t,string a)
    {
        alter *m=p;
        while(m->next)
        {
            if(m->text==t)
                break;
            else
                m=m->next;
        }
        m->text=a;
        cout<<"�޸ĳɹ�"<<endl;
    }
};
int main()
{
    alter l;
    alter *p,*h=new alter;
    h->text="NULL";
    int a;
    cout<<"��ʾ��������0���������1��ɾ������2.�޸�����3"<<endl;
    while(cin>>a)
    {
        string t,s;
        switch(a)
        {
            case 0:
                {
                    p=h;
                    while(p)
                    {
                        cout<<p->text<<endl;
                        p=p->next;
                    }
                    break;
                }
            case 1:
                {
                    cin>>t;
                    l.add(t,h);
                    break;
                }
            case 2:
                {
                    cin>>t;
                    l.del(h,t);
                    break;
                }
            case 3:
                {
                    cout<<"�����޸�ǰ������"<<endl;
                    cin>>t;
                    cout<<"�����޸ĺ������"<<endl;
                    cin>>s;
                    l.alt(h,t,s);
                    break;
                }
            default :
                cout<<"��������"<<endl;
        }
        cout<<"��ʾ��������0���������1��ɾ������2.�޸�����3"<<endl;
    }

}
