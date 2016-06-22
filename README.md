# Password-Cracker
Assignment Description:

Most systems store passwords in an
encrypted manner. So if you were to find the password file, all the data would be in an
unreadable format. However, most passwords are encrypted using a known algorithm. In our
case, the sample password data is encrypted using SHA-1, which is a hashing algorithm first
published in 1995, based on research at the NSA. It is no longer considered a secure hashing
algorithm, because it is relatively simple to compute. For this reason, no real system should use
SHA-1 to encrypt their passwords (though sadly, some of them still do – for example, the
LinkedIn breach in 2012 had passwords stored as SHA-1 hashes).

The premise of a dictionary lookup is pretty simple. You have a list of plain text words which are
commonly used as passwords. You encrypt each of these words using the encryption algorithm,
then compare the encrypted dictionary words against the encrypted words in the password file. If
there’s a match, you’ve now quickly determined the password.

Intel Thread Building Blocks (TBB) is a cross-platform C++ library that assists with
parallelizing software. This allows you to do tasks concurrently across multiple threads. A
dictionary attack is not very computationally expensive, especially when using the SHA-1
algorithm. You can determine thousands of passwords in a matter of seconds. So it doesn’t make
much sense to do it concurrently.

However, if the dictionary lookup fails on a particular password, we will then attempt to brute
force the password. This can take a decent amount of time, and does make sense to parallelize.
Above a certain size, brute forcing passwords can take an inordinate amount of time. For the
constraints of this lab, we will limit non-dictionary passwords to 4 characters which can only be
lower case letters or numbers. That’s roughly 36^4 + 36^3 + 36^2 + 36 possibilities, which is
something like 1.8 million combinations. On my computer, brute forcing a 4 character password
fitting that criteria can be done in less than a second when using TBB.
That’s why it’s best to use pass phrases, which are sentences with many characters. Easy to
remember, and hard to brute force.


This assignment’s starter code is in the pa2 subdirectory. Use either password-windows.sln or
password-mac.xcodeproj. Note that although the starting template for this project only has a
couple of files. It is expected you will add new h/cpp files as appropriate, so that all of your code
isn’t simply in Main.cpp. You will lose all 10 code quality points if you simply put everything in
one file. Think a little bit about how you want to structure your files when you get to part 2 and
3. I will provide some ideas on how to structure your code, but you can implement it in a
different way as long as it’s not sloppy.
You are also provided with two input files for this assignment (they are just in the source code
directory):

pass.txt – This is a list of passwords which have been encrypted using SHA-1.
d8.txt – This is plain text dictionary file which contains a list of commonly used passwords.
