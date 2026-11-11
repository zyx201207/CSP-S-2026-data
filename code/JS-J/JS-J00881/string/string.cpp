#include<bits/stdc++.h>
using namespace std;
int n,a[200005][2];
long long l,ans,temp;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0];l+=a[i][0];
        c=getchar();c=getchar();
        a[i][1]=c-'a'+1;
    }
    int qian=1,hou=n;
    while((temp<l/2)&&(qian!=hou)){
        if(a[qian][0]>a[hou][0]){
            a[qian][0]-=a[hou][0];temp+=a[hou][0];
            if(a[qian][1]!=a[hou][1])ans+=a[hou][0];
            --hou;
        }
        else{
            a[hou][0]-=a[qian][0];temp+=a[qian][0];
            if(a[qian][1]!=a[hou][1])ans+=a[qian][0];
            ++qian;
        }
    }
    if(n==1)cout<<0;
     else cout<<ans;
    return 0;
}
