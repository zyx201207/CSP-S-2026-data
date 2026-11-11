#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long jis=0;
int num[200005];
char zif[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        scanf("%d %s",&num[i],&zif[i]);
    }
    for(int i=1,j=n;i<=n,i<j;i++,j--){
        if(zif[i]==zif[j]){
            if(num[i]>num[j]){
                num[i]-=num[j];
                i--;
            }
            else if(num[i]<num[j]){
                num[j]-=num[i];
                j++;
            }
        }
        else{
            if(num[i]>num[j]){
                jis+=num[j];
                num[i]-=num[j];
                i--;
            }
            else if(num[i]<num[j]){
                jis+=num[i];
                num[j]-=num[i];
                j++;
            }
            else{
                jis+=num[j];
            }
        }
    }
    cout<<jis;
    return 0;
}
