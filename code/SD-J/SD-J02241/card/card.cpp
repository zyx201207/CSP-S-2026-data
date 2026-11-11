#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> ve;
		for(int j=i;j<=n;j++){
			int fid=ve.size()-1;bool isfind=0;		
			for(int k=0;k<ve.size();k++){
				if(ve[k]==a[j]){
					fid=k;
					isfind=1;
					break;
				}
			}
			if(isfind){
				while(!(ve.size()-1==fid)){
					if(ve.size()){
						ve.pop_back();
					}else{
						break;
					}
				}
				ve.pop_back();
			}
			ve.push_back(a[j]);
		}
		for(int i=0;i<ve.size();i++){
			c[ve[i]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<c[j]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
