#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    long long su=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ch[i]=getchar();
        while(!(ch[i]>='a'&&ch[i]<='z')) ch[i]=getchar();
        su+=a[i];
    }
    long long x=0,y=0;
    int i=0,j=n+1;
    while((x+a[i+1])*2ll<=su){
        i++;
        x+=a[i];
    }
    while((y+a[j-1])*2ll<=su){
        j--;
        y+=a[j];
    }
    // cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<a[i+1]<<endl;
    if(i!=j-1){
        if(x>y){
            j--;
            a[j]=x-y;
        }
        else{
            if(x<y){
                i++;
                a[i]=y-x;
            }
        }
    }
    long long ans=0;
    int l=1,r=n;
    x=0;y=0;
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" "<<ch[i]<<endl;
    // }
    while(l<=i||r>=j){
        // cout<<x<<"+"<<a[l]<<" "<<y<<"+"<<a[r]<<endl;
        if(x+a[l]<=y+a[r]&&l<=i){
            if(x<y){
                if(r>=j&&ch[l]!=ch[r]){
                    ans+=x+a[l]-y;
                }
            }
            else{
                if(ch[l]!=ch[r]){
                    ans+=a[l];
                }
            }
            x+=a[l];
            l++;
        }
        else{
            if(x>y){
                if(l<=i&&ch[l]!=ch[r]){
                    ans+=y+a[r]-x;
                }
            }
            else{
                if(ch[l]!=ch[r]){
                    ans+=a[r];
                }
            }
            y+=a[r];
            r--;
        }
        // cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<ans<<" "<<ans1<<endl;
    }
    printf("%lld",ans);
    return 0;
}//orange for 1.1h