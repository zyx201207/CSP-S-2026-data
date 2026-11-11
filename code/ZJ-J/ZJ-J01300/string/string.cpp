#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
int t[200010],pr[200010];
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
		pr[i]=t[i];
		t[i]+=t[i-1];
		if(c[i]==c[i-1]){
			pr[i-1]+=pr[i];
			t[i-1]=t[i];
			n--;
			i--;
		}
	}
	int mid=(t[n]+1)/2;
	int it=upper_bound(t+1,t+n+1,mid)-t;
	int lb=it,rb=it;
	int l,r;
	if(t[n]%2==1){
		l=(mid-t[it-1]);
		r=(t[it]-mid+1);
	}else{
		l=(mid-t[it-1]);
		r=(t[it]-mid);
	}
	int ans=0;
	while(lb!=0&&rb!=n+1){
		if(l>r){
			if(c[lb]!=c[rb]){
				ans+=r;
			}
			l-=r;
			r=pr[++rb];
		}else if(l<r){
			if(c[lb]!=c[rb]){
				ans+=l;
			}
			r-=l;
			l=pr[--lb];
		}else{
			if(c[lb]!=c[rb]){
				ans+=r;
			}
			r=pr[++rb];
			l=pr[--lb];
		}
	}
	cout<<ans<<endl;
	return 0;
}
