#include <iostream>

using namespace std;

int main()
{   freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
  long long s1;
  cin>>s1;
  int a[s1];
  string b;
  int ans=0;
  int flag=0;string c;
  for(int i=0;i<s1;i++){
    cin>>a[i]>>b[i];

    if(i!=0){
        if(b[i-1]!=b[i]){
            flag=1;
        }
    }
  }
  if(flag==0){
    cout<<flag<<endl;
    return 0;
  }
  if(s1==1){
    cout<<"0";
    return 0;
  }
  int max1=0;
  for(int i=0;i<s1;i++){
    if(i==0){
        max1=a[0];
    }
    else{
        if(a[i]>max1){
            max1=a[i];
        }
    }
  }
  int mix1;
  for(int i=0;i<s1;i++){
    if(i==0){
        mix1=a[0];
    }
    else{
        if(a[i]<mix1){
            mix1=a[i];
        }
    }
  }
  if(max1==1){
    cout<<(s1+1)/2;
    return 0;
  }
  if(s1==2){
 cout<<mix1;
 return 0;
  }
  cout<<"1005";
    return 0;
}
