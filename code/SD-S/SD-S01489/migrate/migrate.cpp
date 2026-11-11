#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long a[2000001];
vector<int> ne[2000001];
int ans;
int find1(int st,int en){
	if(st==en){
		return 0;
	}
	for(int i=0;i<ne[st].size();i++){
		if(ne[st][i]==en){
			return 1;
		}
	}
	int min1=find1(st,st+1)+find1(st+1,en),cnt1=1;
	cout<<st<<' '<<en<<' '<<min1<<' '<<cnt1<<endl;
	for(int i=st+2;i<en;i++){
		int x=find1(st,i)+find1(i,en);
		cout<<i<<' '<<x<<' ';
		if(x<min1){
			min1=x;
			cnt1=1;
		}else if(x==min1){
			cnt1++;
		}
		cout<<st<<' '<<en<<' '<<min1<<' '<<cnt1<<endl;
	}
	if(cnt1==2){
		ans++;
	}
	cout<<st<<' '<<en<<' '<<min1<<' '<<cnt1<<endl;
	return min1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T; 
	for(int I=0;I<T;I++){
		ans=0;
		int n;
		long long d;
		cin>>n>>d;
		int j=1;
		for(int i=1;i<=n;i++){
			ne[i].clear();
			cin>>a[i];
			while(a[i]-a[j]>d){
				j++;
			}
			for(int k=j;k<i;k++){
				ne[k].push_back(i);
			}
		}
		int st=1,en=1;
		for(int i=1;i<=n;i++){
			if(!ne[i].size()||i==n){
				en=i;
				find1(st,en);
				st=i+1;
			} 
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
