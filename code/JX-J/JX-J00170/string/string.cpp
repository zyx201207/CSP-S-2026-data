#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005];
long long l,r;
char s[200005];
long long sum,lf,ri,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        a[i]=sum+1;
        sum+=x;
        b[i]=sum;
        s[i]=c;
    }
    l=lf=1,r=n,ri=sum;
    while(l<r){
		
        if(s[l]==s[r]){
            if(sum+1-a[r]==b[l]){
                lf=b[l]+1;
                ri=a[r]-1;
                l++,r--;
            }else if(sum+1-a[r]>b[l]){
                lf=b[l]+1;
                ri=sum+1-lf;
                l++;
            }else{
                ri=a[r]-1;
                lf=sum+1-ri;
                r--;
            }
        }else{
            if(sum+1-a[r]==b[l]){
                ans+=ri-a[r]+1;
                lf=b[l]+1;
                ri=a[r]-1;
                l++,r--;
            }else if(sum+1-a[r]>b[l]){
                ans+=b[l]-lf+1;
                lf=b[l]+1;
                ri=sum+1-lf;
                l++;
            }else{
                ans+=ri-a[r]+1;
                ri=a[r]-1;
                lf=sum+1-ri;
                r--;
                
            }
        }
        if(lf>ri)break;
    }
    cout<<ans;
	return 0;
}

