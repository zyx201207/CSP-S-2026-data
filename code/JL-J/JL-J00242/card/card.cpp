#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(m<=9){
		vector<int> ans(m+1,0);
		for(int i=0;i<n;i++){
			string s;
			for(int j=i;j<n;j++){
				char c=a[j]+'0';
				int pos=-1;
				for(size_t i=0;i<s.size();i++)
					if(s[i]==c){
						pos=i;
						break;
					}
				if(pos!=-1)
					for(size_t i=pos+1;i<s.size();i++)
						s[i]=0;
				else
					s+=c;
			}
			for(size_t i=0;i<s.size();i++)
				ans[s[i]-'0']++;
		}
		for(int i=1;i<m;i++)
			cout<<ans[i]<<' ';
		cout<<ans[m]<<endl;
	}else{
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				cout<<i<<' ';
			}
		}
		cout<<n<<endl;
	}
	
	return 0;
}
