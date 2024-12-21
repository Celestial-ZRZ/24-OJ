#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[1010];

int exgcd(int A,int B,int &x,int &y)
{
    if (!B)
    {
        x=1;
        y=0;
        return A;
    }
    int d=exgcd(B,A%B,x,y);
    int tmp=y;
    y=x-(A/B)*y;
    x=tmp;
    return d;
}


int main()
{
    int T,A,B,x,y;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<T;i++)
    {
        int d=exgcd(a[i].first,a[i].second,x,y);
        if (d!=1) cout<<0<<" "<<0<<endl;
        else cout<<x<<" "<<y<<endl;
    }

    return 0;
}