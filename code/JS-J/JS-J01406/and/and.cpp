#include<bits/stdc++.h>
using namespace std;
int n,m,cord,len1,len2,k,m_orig;
const int N=1e5+5;
int num1[2*N];
vector<int> num3;
vector<int> num2;
int num_exist[2*N];
//int cord[2*N];

/*int sigma(int k1,int k2,int cord[]){
    if(k2==0){
        compared_num=num[cord[0]];
        for(int i=0;i<m;i++){
            compared_num=compared_num&num[i]
        }
    }
    for(cord[k1]=k1;cord[k1]<n;cord[k1]++){
        sigma(k1+1,k2-1,cord[])
    }
}*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num1[i];
        //cout<<num1[i];
        num2.push_back(num1[i]);
        num3.push_back(num1[i]);
    }
    len1=n;
    len2=n;
    m_orig=m;
    while(m>1){
        for(int i=0;i<len1;i++){
            for(int j=i;j<len2;j++){
                k=num1[i]&num2[j];
                //cout<<"num1:"<<num1[i]<<' ';
                //cout<<"num2:"<<num2[j]<<' ';
                //cout<<k<<' ';
                num3.push_back(k);
                //num2.erase(num2.begin());
                num2.push_back(k);
                //cord+=1;
            }
            //num3.erase(num3.begin());
            //num2.erase(num2.begin());
        }
        for(int i=0;i<len1;i++){
            num3.erase(num3.begin());
            num2.erase(num2.begin());
        }
        //for(int i=0;i<num3.size();i++){
         //   cout<<num3[i]<<' ';
    //}
        len2+=len2;
        m-=1;
    }
    sort(num3.begin(),num3.end());
    for(int i=0;i<num3.size();i++){
        num_exist[i]=0;
        //cout<<num3[i];
    }
    int cord=0;
    for(int i=0;i<num3.size();i++){
        if(num_exist[cord]!=num3[i]){
            cord+=1;
            num_exist[cord]=num3[i];
            //cout<<num_exist[cord];
        }
    }

    cout<<num_exist[cord-1-m];
    //for(int i=0;i<num3.size();i++){
       // cout<<num3[i]<<' ';
    //}
    //cout<<num3[num3.size()-1];

    //for(int i=0;i<2*N;i++){
    //    cord[i]=0;
    //}
    //sigma(0,m,cord[2*N])
    return 0;
}
