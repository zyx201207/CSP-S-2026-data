#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>vec(n),ans(m+1);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	for(int i=0;i<n;i++){
		vector<int>card(n),num(m+1);
		int pos=0;
		for(int j=i;j<n;j++){
			if(num[vec[j]]==1){
				int tmppos=0;
				for(int k=0;k<n;k++){
					if(card[k]==vec[j]){
						tmppos=k;
						break;
					}
				}
				for(int k=tmppos+1;k<n;k++){
					num[card[k]]=0;
					card[k]=0;
				}
				pos=tmppos+1;
			}
			else{
				card[pos++]=vec[j];
				num[vec[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(num[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}



