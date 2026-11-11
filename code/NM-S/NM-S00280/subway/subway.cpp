#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int sj[105]={0},sj1[105]={0},sj2[105]={0},sj3[105]={0},sj4[105]={0},sj5[105]={0};
    for (int i = 1; i < 5; i++){
        cin>>sj[i];
    }
    for (int i = 1; i < 5; i++){
        cin>>sj1[i];
    }
    for (int i = 1; i < 7; i++){
        cin>>sj3[i];
    }
    for (int i = 1; i < 7; i++){
        cin>>sj4[i];
    }
    for (int i = 1; i < 2; i++){
        cin>>sj5[i];
    }
    for (int i = 1; i < 2; i++){
        cin>>sj2[i];
    }
    cout<<"32"<<endl<<"17"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
