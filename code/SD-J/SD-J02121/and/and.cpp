#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,m,maxn,ans,mp[200005],a,b,c;
bool A=1,B=1,use[200005];
void dfs(long long num,int step){
	if(step==m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			if(step==0){
				dfs(mp[i],step+1);
			}
			else{
				dfs((num&mp[i]),step+1);
			}
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
bool is(int in){
	for(int i=0;i<=31;i++){
		int num=round(pow(2,i));
		if(num-1==in){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mp[i];
		if(!is(mp[i])){
			A=0;
		}
		if(mp[i]>4){
			B=0;
		}
		if(mp[i]==1){
			a++;
		}
		if(mp[i]==2){
			b++;
		}
		if(mp[i]==3){
			c++;
		}
		maxn=max(maxn,mp[i]);
	}
	if(m==1){
		cout<<maxn<<endl;
	}
	else if(m==n){
		ans=mp[1];
		for(int i=2;i<=n;i++){
			ans=(ans&mp[i]);
			cout<<ans;
		}
		cout<<ans<<endl;
	}
	else if(B){
		if(c>=m){
			cout<<3<<endl;
		}
		else if(b+c>=m){
			cout<<2<<endl;
		}
		else if(a+c>=m){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else if(A){
		sort(mp+1,mp+n+1,cmp);
		cout<<mp[m];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,(mp[i]&mp[j]));
			}
		}
		cout<<ans<<endl; 
	}
	else{
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
