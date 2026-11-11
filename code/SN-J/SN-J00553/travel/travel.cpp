#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string s,m,i,e;
	int n,l,k,j;
	cin>>s>>m>>i>>e;
	if(s[0]==i[0]&&s[1]==i[1]){
		n=1;//che xiang
	}else{
		n=0,l=0,k=0,j=0;
		cout<<n<<l<<k<<j;
		return 0;
	}
	
	
	
	if(m[0]==e[0]&&m[1]==e[1]){
		l=1;//tong pai
	}else{
		l=0,k=0,j=0;
		cout<<n<<l<<k<<j;
		return 0;
	}
	
	
	
	if((m[2]==65&&e[2]==66)||(m[2]==65&&e[2]==67)||(m[2]==66&&e[2]==67)||(m[2]==66&&e[2]==65)||(m[2]==67&&e[2]==66)||(m[2]==67&&e[2]==65)){
		k=1;//tong ce
	}else if((m[2]==68&&e[2]==69)||(m[2]==69&&e[2]==68)){
		k=1;
	}else{
		k=0,j=0;
		cout<<n<<l<<k<<j;
		return 0;
	}
	
	
	
	if((m[2]==68||m[2]==67)&&(e[2]==68||e[2]==67)){
		j=0;
	}else if(m[2]-e[2]==1||m[2]-e[2]==-1){
		j=1;//xiang lin
	}else{
		j=0;
	}
	cout<<n<<l<<k<<j;
	return 0;
}
