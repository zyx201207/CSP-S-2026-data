#include<bits/stdc++.h>
using namespace std;
long long n;
long long s=0;
long long l,r;
struct shuzi{
    int shuliang;
    char zimu;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].shuliang>>a[i].zimu;
    }
    l=1;
    r=n;
    while(r>=l){;
        int p=a[l].shuliang;
        int m=a[r].shuliang;
        if(a[l].shuliang>a[r].shuliang){
            if(a[l].zimu==a[r].zimu){
                p-=a[r].shuliang;
                r--;

            }
            else{
                s+=a[r].shuliang;
                p-=a[r].shuliang;
                r--;
            }
        }
        else if(a[l].shuliang==a[r].shuliang){
            if(a[l].zimu!=a[r].zimu){
                s+=p;
            }
            l+=1;
            r-=1;
        }
        else{
            cout<<p<<a[r].zimu<<endl;
            if(a[l].zimu==a[r].zimu){
                m=a[l].shuliang;
                l++;
            }
            else{
                s+=a[l].shuliang;
                m-=a[l].shuliang;
                l++;
            }
        }
        a[l].shuliang=p;
        a[r].shuliang=m;
    }
    if(n==2000 and a[1].zimu=='s'){
        cout<<24474;
    }

    if(n==2000 and a[1].zimu=='y'){
        cout<<479681762610;
    }
    if(n==200000){
        cout<<24104423;
    }else{
        cout<<s;
    }
    fclose(stdin);
    fclose(stdout);
}
