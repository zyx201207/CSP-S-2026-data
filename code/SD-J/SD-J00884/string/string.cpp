#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int cnt=0;
    int ans=0;
    int n;
    cin>>n;
	for(int i=1;i<=n;i++){
		int c1;
		char s1;
		cin>>c1>>s1;
		for(int i=1;i<=c1;i++){
			s+=s1;
		}
		cnt+=c1;
	} 
	string a=s;
	int i=0;
	int j=cnt-1;
	while(i>=j){
		if(a[i]!=a[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}
