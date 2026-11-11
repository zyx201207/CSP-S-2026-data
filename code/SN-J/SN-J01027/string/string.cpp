#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans,temp,j;
int a[200005];
char c[200005];
bool v=1;
vector<char> s,s1;
void check(vector<char> s){
	s1.clear();
	for(int i=s.size()-1;i>=0;i--){
		s1.push_back(s[i]);
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	temp=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=temp){
			v=0;
		}
	}
	if(v==1){
		if(n/2==0){
			for(int i=1;i<=n/2;i++){
				j=n-i+1;
				if(c[i]!=c[j]){
					ans+=temp;
				}
			}
			cout<<ans;
			return 0;
		}
		else{
			for(int i=1;i<=n/2;i++){
				j=n-i+1;
				if(c[i]!=c[j]){
					ans+=temp;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s.push_back(c[i]);
		}
	}
	check(s);
	for(int i=0;i<s.size()/2+1;i++){
		if(s1[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/


/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans;
int a;
char c;
vector<char> s,s1;
void check(vector<char> s){
	s1.clear();
	for(int i=s.size()-1;i>=0;i--){
		s1.push_back(s[i]);
	}
}
signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s.push_back(c);
		}
	}
//	for(int i=0;i<s.size();i++){
//		cout<<s[i]<<endl;
//	}
	check(s);
	for(int i=0;i<s.size()/2+1;i++){
		if(s1[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
*/
