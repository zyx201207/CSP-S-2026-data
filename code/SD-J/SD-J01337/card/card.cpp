#include<bits/stdc++.h>
using namespace std;
int b[1000005];//数子编号 
int t[1000005]; //统计总数 
int a[1000005]; 
int w[1000005];//统计个数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int f=0;
	cin>>n>>m;
	for (int i=0;i<n;i++) {
	    cin>>b[i];
	    w[b[i]]++; 
	}
	for (int i=0;i<n;i++){
		int s=0;
		w[b[i]]--;
		for (int k=0;k<m;k++){
			a[k]==w[k];
		}
		for (int j=i;j<n;j++){
			int g=b[j];//当前数字 
			if (w[g]==1&&f==0) t[g]++,a[g]--;
			if (w[g]<1&&f==0){
				w[g]--;
				t[g]++;
				f=1;
				s=g;
			}
			if (a[g]==s&&f==1&&w[g]==1){
				a[g]--;
				f=0;
			}
		}
	}
	for (int i=1;i<m+1;i++) cout<<t[b[i]]<<" ";
	return 0;
}
