#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct br{
	int p;
	bool b;
};
br a[500005];
vector<int> v;
map<int,int> ma;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].p;
		a[i].b=false;
		ma[a[i]]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ma[a[i]]==0){
				v.push_back(a[i]);
				ma[a[i]]=1;
			}
			else{
				for(int k=0;k<v.size();k++){
					if(v[k]==a[i].p&&a[i].b==0){
						for(int x=k;x<v.size();x++){
							a[i]
						}
					}
				}
			}
		}
	}
	return 0;
}
