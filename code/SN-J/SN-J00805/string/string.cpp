//姓名：张晨煦   考号：SN-J00805   学校：西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,num;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	int alpha=0;
	for(int i=0;i<n;i++){
		cin>>num>>c;
		for(int j=0;j<num;j++){
			a+=c;
			alpha++;
		}  
	}
	//cout<<b<<'\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
