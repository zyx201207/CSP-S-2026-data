#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	long long n,m;
	fin>>n>>m;
	int e[500005]={0};
	long long ans=0; 
	long long k=0;
	for(int i=0;i<n;i++){
		fin>>e[i];
	}
	
	sort(e,e+n-1);
	long long t=m;
	long long cnt=1;
	for(int i=0;i<n;i++){
		
		t=m;
		cnt=1;
		
		for(int j=i-1;j>=0;j--){
			if(t>=e[i]-e[j]){
				t=t-(e[i]-e[j]);
				cnt++;
			}
			else{
				break;
			}
		} 
		
		if(ans<cnt)	ans=cnt;
	}
	fout<<ans;
	return 0;
}
