#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[3],s2[3];
	long long a=0,c1,c2;
	int q[100]={0};
	long long z=17;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		q[0]=1;
	}
	else{
		for(int i=0;i<4;i++)
			cout<<q[i];
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		q[1]=1;
		a=1;
}
	q[2]=1;
	if((s1[2]<'D'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<'D'))
		q[2]=0;
	if(q[1]==0) q[2]=0;
	if((a==1&&s1[2]+0==s2[2]+1)||(a==1&&s1[2]+0==s2[2]-1)&&q[2]==1)
		q[3]=1;
	if((s1[1]==s2[1]+1||s1[1]==s2[1]-1)&&(s1[2]==s2[2]))
		q[3]=1;
	for(int i=0;i<4;i++)
		cout<<q[i];
	cout<<endl;
	return 0;
}
