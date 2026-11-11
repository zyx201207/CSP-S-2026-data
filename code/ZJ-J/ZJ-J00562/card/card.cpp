#include<bits/stdc++.h>
using namespace std;
const int N=500001;
long long n,m,a[N],anc[N],q,w;
bool card[N];
vector<long long> table;
int main(){
	
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<m;i++){
		for(int j=i;j<n;j++){
			if(card[a[i]]==0){
				card[a[i]]=1;
				table.push_back(a[i]);
				w++;
			}else{
				card[a[i]]=0;
				while(table.back()!=a[i]){
					card[table.back()]=0;
					table.pop();
					w--;
				}
				table.pop();
				w--;
			}
		}
		for(int i=0;i<w;i++){
			anc[table[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<anc[i]<<' ';
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
