#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n>> m;
	int a[m];
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	int beichu=0,jieguo=0;
	string yushu;
	for(int i=0;i<n;i++){
		int jieguo=a[i];
		int beichu=jieguo;
		if(beichu<2){
			continue;
		}
		for(int j=i;j<=n;j++){
		
			jieguo=beichu/2;
			yushu[i]=beichu%2;
	    }
	    a[i]=yushu[i]; 
	}
	for(int i=n;i>=0;i--){
		cin>> yushu[i];
	}
		
	return 0;
}
