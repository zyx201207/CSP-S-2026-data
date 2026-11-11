#include<bits/stdc++.h>
using namespace std;
long long sum=0;
struct hwsd{
    int a;
    char b;
}s[300000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    int i=1,j=n;
    while(i < j){
        if(s[i].b != s[j].b){
            if(s[i].a > s[j].a){
                sum+=1ll*s[j].a;
                s[i].a = s[i].a - s[j].a;
                j--;
            }else if(s[i].a < s[j].a){
                sum+=1ll*s[i].a;
                s[j].a = s[j].a - s[i].a;
                i++;
            }else{
                sum+=1ll*s[i].a;
                j--;
                i++;
            }
        }else{
            if(s[i].a > s[j].a){
                s[i].a = s[i].a - s[j].a;
                j--;
            }else if(s[i].a < s[j].a){
                s[j].a = s[j].a - s[i].a;
                i++;
            }else{
                j--;
                i++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
