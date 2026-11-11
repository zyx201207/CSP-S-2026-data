#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
int all[300005],maxn=0;
void mu(int now){
	int new1[500005];
	int st=1,end1=0;
	for(int i=1;i<=now;i++){
		bool ys=false;
		int rem;
		for(int j=1;j<=end1;j++){
			if(new1[i]==new1[j]){
				ys=true;
				rem=j;
			}
		}
		if(ys) end1=rem;
		else{
			end1++;
			new1[end1]=a[i];
		} 
	}
	sort(new1+1,new1+end1);
	all[new1[1]]++;
	for(int i=2;i<=end1;i++){
		if(new1[i]!=new1[i-1]){
			new1[i]++;
		}
	}
}
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.ans","w",stdout);
	freopen("card2.in","r",stdin);
	freopen("card2.ans","w",stdout);
	freopen("card3.in","r",stdin);
	freopen("card3.ans","w",stdout);
	freopen("card4.in","r",stdin);
	freopen("card4.ans","w",stdout);
	freopen("card5.in","r",stdin);
	freopen("card5.ans","w",stdout);
	freopen("card6.in","r",stdin);
	freopen("card6.ans","w",stdout);
	
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mu(i);
	}
	for(int i=1;i<=m;i++){
		cout<<all[i]<<' ';
	}
	return 0; 
} 
