#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(" string.in ","r",stdin);
	freopen(" string.out","w",stdin);
	int n;
	cin>>n;
	int k;
	
	string s="";
	int cnt=0,ans=0;

	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		while(a--){
			s+=c;
			cnt++;
		}
	}
	int dq=0;
	if(n%2==1){
		k=cnt/2+1;
		dq=cnt/2-1;
	} 
	else{
		k=cnt/2+1;
		dq=cnt/2;
	} 
	for(int i=k;i<cnt;i++){
		if(s[i]!=s[dq]) ans++;
		dq--;
	}
	cout<<ans;//<<" "<<k<<" "<<cnt
	return 0;
}



//	for(int i=1;i<=n;i++){
//		int a;
//		string c;
//		cin>>a>>c;
//		while(a--){
//			s+=c;
//			if(cnt>k){
//				if(s[cnt]!=s[k-(cnt-k)]){
//					ans++;
//					
//				}
//			}
//			cnt++;
//			
//		}
//		
//		
//	}
