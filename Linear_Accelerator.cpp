#include<bits/stdc++.h>
using namespace std;

long long exgcd(long long A,long long B,long long &x,long long &y)
{
    if (!B)
    {
        x=1;
        y=0;
        return A;
    }
    long long d=exgcd(B,A%B,x,y);
    long long tmp=y;
    y=x-(A/B)*y;
    x=tmp;
    return d;
}

int main() 
{
    long long T,A,B,C,x,y,d;
    pair<long long,long long>a;
    pair<long long,long long>b;
    cin>>T;
    while(T--)
    {
        cin>>a.first>>a.second>>b.first>>b.second;
        A=a.second-b.second;
        B=b.first-a.first;

        d=exgcd(A,B,x,y);
        C=b.first/d*a.second-a.first/d*b.second;

        if (d>0 && C>0) 
        {
            if (!(C%d)) cout<<x*(C/d-1)<<" "<<y*(C/d-1)<<endl;
            else        cout<<x*(C/d)<<" "<<y*(C/d)<<endl;
        }
        else if (d>0 && C<0)
        {
            if (!(C%d)) cout<<x*(C/d+1)<<" "<<y*(C/d+1)<<endl;
            else        cout<<x*(C/d)<<" "<<y*(C/d)<<endl;
        }
        else if (d<0 && C>0)
        {
            if (!(C%d)) cout<<x*(C/d-1)<<" "<<y*(C/d-1)<<endl;
            else        cout<<x*(-C/d)<<" "<<y*(-C/d)<<endl;
        }
        else if (d<0 && C<0)
        {
            if (!(C%d)) cout<<x*(C/d+1)<<" "<<y*(C/d+1)<<endl;
            else        cout<<x*(C/d)<<" "<<y*(C/d)<<endl;
        }
    }

    return 0;
}