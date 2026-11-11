#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int vis[3005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i=1;i<=n;i++){
		string s=""; 
		for(int j=i;j<=n;j++){
			char c=a[j]+'0';
			//cout << c <<" ";
			int aus=0;
			
			int num=s.find(c);
			//cout << num <<" ";
			if(s.find(c)==-1){
				s+=c;
			}else{
				//cout << "uzi "; 
				for(int i=0;i<s.size();i++){
					if(s[i]==c){
						aus=i;
					}
				}
				for(int i=aus;i<s.size();i++){
					s[i]='d'; 
				}
				s+=c;
			}
		}
		//cout << s <<" ";
		for(int i=0;i<s.size();i++){
			if(s[i]!='d'){
				int sum=s[i]-'0';
				vis[sum]++;
				//cout << vis[sum] << " " << sum << " ";
			}
				
		}
		
	} 
	for(int i=1;i<=m;i++){
		cout <<vis[i] << " ";
	}
	return 0;
}
