#include <bits/stdc++.h>
using namespace std;
int a[2000001];
int d,g,n;
pair <int,int> b;
void dfs(int step,int ad){
	if (ad==g){
		if (step<=b.first){
			b.first=step;
			b.second++;
			if (step<b.first){b.second=1;}
		}
		return ;
	}
	for (int i=1;a[i]-ad<=d&&i<=n;i++){
		if (step>=b.first){return ;}
		dfs(step++,a[i]);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		int ans=0;
		cin>>n>>d;
		b.first=INT_MAX;
		for (int i=1;i<=n;i++){cin>>a[i];}
		for (int i=1;i<=n;i++){
			for (g=i;g<=n;g++){
				dfs(0,i);
				if (b.second==2){ans++;}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
