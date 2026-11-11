#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,a[500004]={0},ans[300004]={0};
bool f[300004]={0};
vector<int> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		memset(f,0,sizeof(f));
		while(!c.empty())c.pop_back();
		for(int j=i;j<n;j++){
			if(f[a[j]])while(c.back()!=a[j])c.pop_back();
			else{
			f[a[j]]=1;
			c.push_back(a[j]);
			}
		}
		for(int e:c)ans[e]++;
	}
	cout<<ans[1];
	for(int i=2;i<=m;i++)cout<<' '<<ans[i];
	fclose(stdin);
	fclose(stdout);
}