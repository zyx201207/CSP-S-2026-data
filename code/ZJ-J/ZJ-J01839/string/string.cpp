#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cjj_n;
	cin>>cjj_n;
	int cjj_a[200005],cjj_num=0;
	char cjj_c[200005];
	for(int i=1;i<=cjj_n;i++){
		cin>>cjj_a[i];
		cin>>cjj_c[i];
		cjj_num+=cjj_a[i];
	}
	int cntq=1,cnth=cjj_n;
	long long chenchenkx=0; 
	while(cntq<cnth){
		if(cjj_c[cntq]!=cjj_c[cnth]){
			if(cjj_a[cntq]>cjj_a[cnth]){
				chenchenkx+=cjj_a[cnth];
				cjj_a[cntq]-=cjj_a[cnth];
				cnth--;
			}
			else if(cjj_a[cntq]<cjj_a[cnth]){
				chenchenkx+=cjj_a[cntq];
				cjj_a[cnth]-=cjj_a[cntq];
				cntq++;
			}
			else{
				chenchenkx+=cjj_a[cnth];
				cnth--;
				cntq++;
			}
		}
		else{
			if(cjj_a[cntq]>cjj_a[cnth]){
				cjj_a[cntq]-=cjj_a[cnth];
				cnth--;
			}
			else if(cjj_a[cntq]<cjj_a[cnth]){
				cjj_a[cnth]-=cjj_a[cntq];
				cntq++;
			}
			else{
				cnth--;
				cntq++;
			}
		}
	}
	cout<<chenchenkx;
	return 0;
} 
