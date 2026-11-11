#include<bits/stdc++.h>
using namespace std;
int n[541888],n2[541888],n2i,lastm[325799],m[325799];
bool ismappear[325799];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
    	cin>>n[i];
    }
    if(b==1){
    	cout<<a;
    }
    else if(b==2){
    	for(int i=0;i<a;i++){
    	    if(n[i]==1 && n[a-1]==1) m[1]++;
    	    else if((n[i]==1 && n[a-1]==2) or (n[i]==2 && n[a-1]==1)) m[1]++,m[2]++;
    	    else m[2]++;
    	}
    	cout<<m[1]<<' '<<m[2];
    }
    else if(a<=500){
    	for(int i=0;i<a;i++){
    	    n2i=0;
    	    for(int j=1;j<=b;j++) ismappear[j]=0;
    	    for(int j=i;j<a;j++){
    	    	for(int k=n2i-1;k>=0;k--){
    	    	    if(n2[k]==n[j]){n2i=k;break;}
    	    	}
    	    	n2[n2i++]=n[j];
    	    }
    	    //cout<<"In Game #"<<i<<':';
    	    for(int j=0;j<n2i;j++){
    	    	ismappear[n2[j]]=1;
    	    	//cout<<n2[j]<<' ';
    	    }
    	    for(int j=1;j<=b;j++) m[j]+=ismappear[j];
    	    //cout<<endl;
    	}
    	for(int i=1;i<=b;i++) cout<<m[i]<<' ';
    }
    else{
    	for(int i=0;i<a;i++){
    	    n2i=0;
    	    for(int j=1;j<=b;j++) lastm[j]=-1,ismappear[j]=0;
    	    for(int j=i;j<a;j++){
    	    	if(lastm[n[j]]+1) n2i=lastm[n[j]];
    	    	else lastm[n[j]]=n2i;
    	    	n2[n2i++]=n[j];
    	    }
    	    //cout<<"In Game #"<<i<<':';
    	    for(int j=0;j<n2i;j++){
    	    	ismappear[n2[j]]=1;
    	    	//cout<<n2[j]<<' ';
    	    }
    	    for(int j=1;j<=b;j++) m[j]+=ismappear[j];
    	    //cout<<endl;
    	}
    	for(int i=1;i<=b;i++) cout<<m[i]<<' ';
    }
    return 0;
}
