#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long cnt=0;
long long i=0,j=0,l=1,r=1,sum=0;
long long a[N],a1[N];
char s[N],s1[N];
int n;
void print(){
    for(int i=1;i<=n;i++){
        if(i==l){
            cout<<'>';
        }
        cout<<a[i]<<' '<<s[i]<<' '<<a1[i]<<' '<<s1[i];
        if(i==r){
            cout<<'<';
        }
        cout<<endl;
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        a1[n-i+1]=a[i];
        s1[n-i+1]=s[i];
        sum+=a[i];
    }
    while(i<sum){
        i+=a[l];
        while(i>j){
            if(s[l]==s1[r]){
                if(a[l]>=a1[r]){
                    a[l]-=a1[r];
                    j+=a1[r];
                    r++;
                }else{
                    a1[r]-=a[l];
                    j=i;
                }
            }else{
                if(a[l]>=a1[r]){
                    a[l]-=a1[r];
                    cnt+=a1[r];
                    j+=a1[r];
                    r++;
                }else{
                    a1[r]-=a[l];
                    cnt+=a[l];
                    j=i;
                }
            }
        }
        l++;
    }
    cout<<cnt/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//sto CCF orz ccw.site chat.deepseek.com
//ygg luogu:yjh_114514 ACGO:2433437 bilibili:xiao yan bu yan ya
//X X XXX  X X XXX
//ciallo~
//phigros MC BA
//love CCF
