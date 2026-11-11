#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001]={0},cnt[300001]={0};
vector<int>v;
bool b[300001]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0){
			v.push_back(a[i]);
			b[a[i]]=1;
		}
		else{
			for(int j=v.size()-1;v[j]!=a[i];j--){
				v.pop_back();
			}
		}
		for(int j=0;j<v.size();j++){
			cnt[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
