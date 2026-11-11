#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],mid,midi,pre[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
	}
	mid=pre[n]/2;
	for(int i=1;i<=n;i++){
		if(pre[i]>=mid){
			midi=i;
			break;
		}
	}
	int r=n,rr=a[n];
	for(int i=1;i<=midi;i++){
		int rest=min(a[i],mid-pre[i-1]);
		char nc=c[i];
		while(rest){
			if(c[r]==nc){
				rest-=min(rest,rr);
				rr-=min(rest,rr);
				if(!rr){
					r--;
					rr=min(a[r],pre[r]-mid);
				}
			}
			if(c[r]!=nc){
				ans+=min(rest,rr);
				rest-=min(rest,rr);
				rr-=min(rest,rr);
				if(!rr){
					r--;
					rr=min(a[r],pre[r]-mid);
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
