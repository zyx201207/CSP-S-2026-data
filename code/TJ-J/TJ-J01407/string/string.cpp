#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char> s;
bool check(){
	return 0;
}
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t,r;
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>t;
		cin>>r;
		for(int j=0;j<t;j++){
			s.push_back(r);
		}
    }
    for(unsigned long i=0;i<s.size();i++){
		cout<<s[i];
	}
    return 0;

}
