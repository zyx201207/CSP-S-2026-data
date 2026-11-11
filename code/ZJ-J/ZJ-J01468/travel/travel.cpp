#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;
string a[]={"","","",""};
int l[]={0,0,0,0};
bool b[]={false,false,false,false};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++){
		cin>>a[i];
		l[i]=stoi(a[i]);
	}
	if(l[0]==l[2])b[0]=true;
	if(b[0]&&(l[1]==l[3]))b[1]=true;
	if(b[0]&&b[1]){
		if(a[1].back()<'D'&&a[3].back()<'D'||a[1].back()>'C'&&a[3].back()>'C'){
			b[2]=true;
		}
	}
	if(b[0]&&b[1]&&b[2]){
		if(abs(a[3].back()+0-a[1].back())==1){
			b[3]=true;
		}
	}
	for(int i=0;i<4;i++){
		cout<<b[i];
	}
	return 0;
}
