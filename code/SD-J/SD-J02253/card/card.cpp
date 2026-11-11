# include <bits/stdc++.h>
using namespace std;
int n,m,arr[500005],cnt[300005];
bool k[300005];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		v.erase(v.begin(),v.end());
		for(int j=1;j<=300005;j++){
			k[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(k[arr[j]]==1){
				vector<int>::iterator a;
				for(vector<int>::iterator it=v.begin();it!=v.end();++it){
					if(*it==arr[j]){
						a=it;
						break;
					}
				}
				for(vector<int>::iterator it=a;it!=v.end();++it){
					k[*it]=0;
				}
				v.erase(a,v.end());
			}
			k[arr[j]]=1;
			v.push_back(arr[j]);
		}
		for(vector<int>::iterator it=v.begin();it!=v.end();++it){
			cnt[*it]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
