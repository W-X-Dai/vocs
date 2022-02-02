#include<bits/stdc++.h>
using namespace std;

string S1,S2,s1,s2,s[1005][1005];
double lcs[1005][1005];
int n,i,j,l,n1,n2,len;

void LCS(){

}

int main(){ 
        n1=S1.size();
        n2=S2.size();
        len=min(n1,n2);
        for(int i=0;i<n1;i++)s1[i+1]=S1[i];
        for(int i=0;i<n2;i++)s2[i+1]=S2[i];
	    for(int i=0;i<=n1;i++)lcs[i][0]=0;
	    for(int j=0;j<=n2;j++)lcs[0][j]=0;
	
	    for(int i=1;i<=n1;i++)
	        for(int j=1;j<=n2;j++)
	            if(s1[i]==s2[j]){
	                lcs[i][j]=lcs[i-1][j-1]+1;
	            }
	            else{
	                if(lcs[i-1][j]<lcs[i][j-1]){
	                    lcs[i][j]=lcs[i][j-1];
	                }
	                else{
	                    lcs[i][j]=lcs[i-1][j];
	                }
	            }
	
	    cout<<lcs[n1][n2]/len<<'\n';
    

}




//test data
/*
contribute
attribute
*/
