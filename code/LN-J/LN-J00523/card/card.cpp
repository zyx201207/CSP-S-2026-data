#include<bits/stdc++.h>
using namespace std;


int n,m;
vector<int> a={0},ick;
vector<int> ans;

int main(){
	freopen("card.in","r",stdin);//@@@@@@@@@@@@@@@@@@
	freopen("card.out","w",stdout);//@@@@@@@@@@@@@@@@@@@@2
	
	cin>>n>>m;
	a.resize(n+5);
	ans.resize(m+5);
	for(int i=1,ip;i<=n;i++){
		cin>>ip;
		a[i]=ip;
	}
	
	bool hv=0;
	int d=0;
	for(int i=1;i<=n;i++){
		ick.clear();
		
		for(int j=i;j<=n;j++){
			hv=0;
			d=0;
			for(int k=0;k<(int)ick.size();k++){
				if(ick[k]==a[j]){
					hv=1;
					d=k;
					break;
				}
			}
			if(hv==1){
				ick.resize(d+1);
			}
			else{
				ick.push_back(a[j]);
			}
		}
		for(auto it:ick){
			ans[it]++;
		}
	}
					
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	
	
	fclose(stdin);//@@@@@@@@@@@@@@@@@@@@@
	fclose(stdout);//@@@@@@@@@@@@@@@@@@@@@@@
	return 0;
}
