#include<bits/stdc++.h>
using namespace std;


int n,m,ans;
vector<int> knd={0};

///baoli
///vector<int> bl={0};

bool f(int aa,int bb){
	return aa>bb;
}

int main(){
	freopen("and.in","r",stdin);//@@@@@@@@@@@@@@@@@@
	freopen("and.out","w",stdout);//@@@@@@@@@@@@@@@@@@@@2
	
	cin>>n>>m;
	
	
	
	for(int i=1,ip;i<=m;i++){
		cin>>ip;
		knd.push_back(ip);
	}
	sort(knd.begin()+1,knd.end(),f);
///	////////
///	for(auto ki:knd){
///		cout<<ki<<endl;
///	}
///	cout<<endl;
///	/////////
	for(int i=m+1,ip;i<=n;i++){
		cin>>ip;
		knd.push_back(ip);
		sort(knd.begin(),knd.end(),f);
		knd.pop_back();
		
	///	////////
///		for(auto ki:knd){
///			cout<<ki<<endl;
	///	}
	///	cout<<endl;
///		/////////
	}
	
	
	ans=knd[1];
	for(int i=2;i<=m;i++){
		ans&=knd[i];
	}
	
	cout<<ans;
	
	/// ///////
	/*
	for(int i=1,ip;i<=n;i++){
		cin>>ip;
		bl.push_back(ip);
		
	}
	
	sort(bl.begin()+1,bl.begin()+n);
	
	
	ans=bl[n];
	
	for(int i=n-1;i>=n-m+1;i--){
		ans&=bl[i];
	}
	cout<<ans;
	*/
	/// ///////////
	
	
	
	fclose(stdin);//@@@@@@@@@@@@@@@@@@@@@
	fclose(stdout);//@@@@@@@@@@@@@@@@@@@@@@@
	return 0;
}
