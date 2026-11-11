#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		string ss;
		cin>>ss;
		for(int x=1;x<=j;x++){
			s+=ss;
		}
	}
	/*cout<<s<<endl;
	for(int i=0;i<=n+1;i++){
		cout<<s[i];
	}*/
	int ans=0;
	for(int i=0;i<=n/2;i++){
		if(s[i]!=s[n-i]){
		//	cout<<s[i]<<s[n-i-1]<<" ";
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
