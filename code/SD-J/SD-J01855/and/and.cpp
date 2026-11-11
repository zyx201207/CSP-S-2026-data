#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200005][40],m,ok,cnt,ans2[40],op,ann[100005];//i÷–—°j 
long long as;
long long cc(int x){
	long long cct=1;
	for(int i=1;i<=x;i++){
		cct*=2;
	}
	return cct;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ans;
		int op=0;
		while(ans){
			a[i][++op]=ans%2;
			//cout<<a[i][op]<<" ";
			ans/=2;
		}
	}
	int p=0;
	for(int i=31;i>=1;i--){
		int cnt2=0;
		for(int j=1;j<=n;j++){
			if(ann[j])continue;
			if(a[j][i]==1){
				cnt2++;
			}
		}
		if(cnt2>=m){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0){
					ann[j]=1;
			}
		}
			p=1;
			ans2[i]=1;
			//cout<<1;
		}
		else if(p){
			break;
		}
		
	}
	for(int i=31;i>=1;i--){
		if(ans2[i]==1){
			//cout<<1;
			as+=cc(i-1);
		}
	}
	cout<<as;
	return 0;
} 
