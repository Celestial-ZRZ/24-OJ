#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string a;
    for (int i=1;i<=n;i++){
        a=to_string(i);
        if (a.find('7')!=string::npos || i%7==0) cout<<"PASS"<<endl;
        else cout<<i<<endl;
    }

    return 0;
}