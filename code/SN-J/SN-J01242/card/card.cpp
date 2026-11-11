#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;

int a[N];
bool vis[N];
//set<int> st;
string s;
int num[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(vis,0,sizeof vis);
		s="";
		for(int i=k;i<=n;i++){
			//if(st.size()!=m)st.insert(a[i]);
			if(s.find(to_string(a[i]))!=string::npos){
				int pos=s.find(to_string(a[i]));
				for(int j=pos;j<=s.length();j++)vis[j]=1;
				s+=to_string(a[i]);	
			}else{
				s+=to_string(a[i]);
			}
			//cout<<s<<endl;
		}
		for(int i=k;i<=n;i++){
			if(!vis[i]){
				//cout<<a[i]<<" ";
				num[a[i]]++;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		if(num[i])cout<<num[i]<<" ";
	}
	
	return 0;
} 

