#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	char a[3];
	char b[3];
	for(int i=0;i<s1.size();++i){
		a[i]=(char)s1[i];
		b[i]=(char)s2[i];
	}
	
	int aa=(int)a[2];
	int bb=(int)b[2];
	int sum=aa+bb;
	if(c1==c2){//同节车厢 
	cout<<"1";
	if(a[0]==b[0] && a[1]==b[1]){//同排 
		cout<<"1";
		if(sum==132 || sum==133 || sum==131 ||sum==138 ){//同侧 
				cout<<"1";
				if(sum==131 || sum ==133 || sum==138 )	cout<<"1" ;//相邻	
				else cout<<"0";
		}
		else cout<<"00";
	}else{
		cout<<"000";
	}
	}else{
		cout<<"0000";
	} 
	return 0;
} 
