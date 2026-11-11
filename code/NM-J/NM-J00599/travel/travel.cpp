#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a,b;
	char c,d;
	
	int ans1=0,ans2=0,ans3=0,ans4=0;
	cin >> c1 >> s1 >> c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		ans1=0;
	}
	if(c1==c2){
		ans1=1;
	}
	for(int i =0;i<2;i++){
		if(s1[i]!='0'){
			a+=s1[i];
		}
		if(s2[i]!='0'){
			b+=s2[i];
		}	
		
	}
	c=s1[2];
	d=s2[2];
	bool e=a==b;
	bool e2=ans1==1;
	if(e&&e2){
		ans2=1;
	}
	bool o1=(c<='C'&&d<='C');
	bool o2=(c>'C'&&c<='F');
	bool o3=(d>'C'&&d<='F');
	bool o4=(o2&&o3);
	bool o5=o1||o4;
	if(o5&&ans2==1&&ans1==1){
		ans3=1;
	}
	bool a1=(c=='A'&&d=='B');
	bool a2=(c=='B'&&(d=='A'||d=='C'));
	bool a3=(c=='C'&&d=='B');
	bool a4=(c=='D'&&d=='F');
	bool a5=(c=='F'&&d=='D');
	bool a6=a1||a2||a3||a4||a5;
	bool a9=ans1==1&&ans3==1;
	bool a8=ans2==1&&a9;
	bool a7=a6&&a8;
	if(a7){
		ans4=1;
	}
	
	
	cout << ans1<<ans2<<ans3<<ans4;
	return 0;
}
