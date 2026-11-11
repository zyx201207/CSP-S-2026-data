#include<bits/stdc++.h>
using namespace std;
int main(){
char ch;
string st;
long long n,ct[200010];
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long i=1;i<=n;i++){
    cin>>ct[i]>>ch;
    //cout<<st.size()<<endl;
    for(long long j=1;j<=ct[i];j++){
        st=st+ch;
        //cout<<st<<endl;
    }

}
long long as=0;
long long l=0,r=st.size()-1;
while(l<r){
    if(st[l]!=st[r]){
        as++;
    }
    l++;
    r--;
}
cout<<as;

return 0;
}
