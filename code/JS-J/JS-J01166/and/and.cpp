#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[200005];
bool ab[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ab[i]=1;
	}
	int k=(1<<30);
	while(k){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(ab[i]){
                if(a[i]&k){
                    cnt++;
                }
            }
        }
        if(cnt>=m){
            ans+=k;
            for(int i=1;i<=n;i++){
                if(ab[i]){
                    if((a[i]&k)==0){
                        ab[i]=0;
                    }
                }
            }
        }
        k>>=1;
	}
	printf("%d",ans);
	return 0;
}
