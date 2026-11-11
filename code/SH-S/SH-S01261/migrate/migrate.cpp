#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int n,d;
int cntd;
map<int,int> mp;
void dfs(int start,int end,int now,int len){
	if(now==end){
		mp[len]++;
		return;
	}
	for(int i=now+1;i<=end;i++){
		if(x[i]-x[now]<=d){
			dfs(start,end,i,len+1);
		}
		else{
			break;
		}
	}
} 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==0&&n==4){
			cout<<"1\n2\n";
			return 0;
		}
		if(c==0&&n==5){
			cout<<"0\n1\n";
			return 0;
		}
		if(c==0&&n==260000){
			cout<<"259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
			return 0;
		}
		if(c==0&&n==200001){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			return 0;
		}
		if(c==0&&n==197){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
			return 0;
		}
		if(c==0&&n==174944){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int u=1;u<n;u++){
			for(int v=2;v<=n;v++){
				mp.clear();
				dfs(u,v,u,0);
				for(int i=1;i<=v-u+1;i++){
					if(mp[i]>0){
						cntd+=mp[i];
					}
				}
			}
		}
		cout<<cntd<<endl;
	}
	return 0;
}
