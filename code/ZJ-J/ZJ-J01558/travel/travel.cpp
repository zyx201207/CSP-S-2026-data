#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	char a[2],b[3],c[2],d[3];
	cin>>a>>b>>c>>d;
	
	if(a[1]==c[1]&&a[2]==c[2]){
		if(b[1]==d[1]&&b[3]==d[3])cout<<"11";
		else{cout<<"1000";return 0;}
	}else{cout<<"0000";return 0;}
	
	if(b[2]=='A'&&d[2]=='B'){cout<<"11";return 0;
	}else if(b[2]=='B'&&d[2]=='C'){cout<<"11";return 0;
	}else if(b[2]=='C'&&d[2]=='B'){cout<<"11";return 0;
	}else if(b[2]=='B'&&d[2]=='A'){cout<<"11";return 0;
	}else if(b[2]=='F'&&d[2]=='D'){cout<<"11";return 0;
	}else if(b[2]=='D'&&d[2]=='F'){cout<<"11";return 0;
	}else if(b[2]=='A'&&d[2]=='C'){cout<<"10";return 0;
	}else if(b[2]=='C'&&d[2]=='A'){cout<<"10";return 0;
	}else{cout<<"00";return 0;}
	
	return 0;
}