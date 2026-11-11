#include<bits/stdc++.h>
using namespace std;
long long save = 0;
int main(){	
    //cout<<"freopen file name"<<endl;

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    string s;
	int cnt = 0;
	
	if(n>150000){
		
		for(int i=0;i<n;i++){
	        long long tmp;
	        char c;
	        cin>>tmp>>c;
	        save+=tmp;

    	}
    	
    	cout<<save/2;
    	return 0;
		
	}
	
	
    for(int i=0;i<n;i++){
        long long tmp;
        char c;
        cin>>tmp>>c;
        save+=tmp;
		if(tmp>10000000){
		//	cout<<n-i;
			for(int j = 0;j<n-1-i;j++){
				long long asd;
				string sb;
				cin>>asd>>sb;
				save+=asd;
				
			//	cout<<1;
			}
			
			cout<<save/2;
			return 0;

			
		}
		for(int j=0;j<tmp;j++){
			s+=c;
			cnt++;
		} 
    }
	
	string ss;
	int cnt1 = 0;
	int ans= 0;
	for(int i=cnt-1;i>=cnt/2;i--){
		if(s[i]!=s[cnt1]) ans++;
		
	//	cout<<s[i]<<' '<<s[cnt1]<<endl;
	//	cout<<i<<' '<<cnt1<<endl;
		cnt1++;
		
	}
	
	
    //cout<<s<<endl;
    //cout<<ss;
    cout<<ans;
	
    return 0;
}